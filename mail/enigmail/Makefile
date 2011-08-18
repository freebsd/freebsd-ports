# New ports collection makefile for:	enigmail
# Date created:			20 January 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enigmail
PORTVERSION?=	1.3
PORTREVISION?=	0
CATEGORIES=	mail security
MASTER_SITES=	http://www.mozilla-enigmail.org/download/source/
PKGNAMEPREFIX=	${GECKO}-

MAINTAINER=	ale@FreeBSD.org
COMMENT?=	A GnuPG extension for the Mozilla mail clients

EXTRACT_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/${GECKO_PORTDIR}:${GECKO_TARGET} \
		${GECKO}:${PORTSDIR}/${GECKO_PORTDIR} \
		gmake:${PORTSDIR}/devel/gmake \
		intltool-extract:${PORTSDIR}/textproc/intltool \
		${LOCALBASE}/libdata/pkgconfig/printproto.pc:${PORTSDIR}/x11/printproto
BUILD_DEPENDS=	${GECKO}:${PORTSDIR}/${GECKO_PORTDIR}
RUN_DEPENDS=	${GECKO}:${PORTSDIR}/${GECKO_PORTDIR} \
		gpg:${PORTSDIR}/security/gnupg

.if !defined(GECKO)
GECKO=		libxul
GECKO_PORTDIR=	www/${GECKO}
IGNORE=		is an abstract port: use one of the slave ports
.endif

.if ${PORTVERSION} == "1.0.1" || ${PORTVERSION} == "1.1.2"
GECKO_TARGET=	configure
.else
GECKO_TARGET=	build
.endif

.if defined(GECKO_EXTDIR)
GECKO_WRKSRC=	${WRKDIR}/../../../${GECKO_PORTDIR}/work/${GECKO_EXTDIR}
WRKSRC=		${WRKDIR}/${GECKO_EXTDIR}
MOZSRC=		${WRKSRC}/mozilla
.else
GECKO_WRKSRC=	${WRKDIR}/../../../${GECKO_PORTDIR}/work/mozilla
WRKSRC=		${WRKDIR}/mozilla
MOZSRC=		${WRKSRC}
.endif

USE_GMAKE=	yes

.include <bsd.port.pre.mk>

XPI_FILE=	${MOZSRC}/dist/bin/${DISTNAME}-freebsd-${ARCH}.xpi
XPI_LIBDIR=	${PREFIX}/lib/xpi
XPI_ORIG_ID=	{847b3a00-7ab1-11d4-8f02-006008948af5}
XPI_ID=		${GECKO}@mozilla-enigmail.org

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} -Rp ${GECKO_WRKSRC} ${WRKDIR}
	@for f in ${EXTRACT_ONLY}; do \
		cd ${WRKSRC}/mailnews/extensions && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$f ${EXTRACT_AFTER_ARGS}; \
	done

pre-patch:
	@${REINPLACE_CMD} -e "s|${GECKO_PORTDIR}|mail/enigmail-${GECKO}|g" \
		`${FIND} ${WRKSRC} -name autoconf.mk`

post-patch:
	${REINPLACE_CMD} "s/^XPI_MODULE_VERS = [0-9.]*/XPI_MODULE_VERS = ${PORTVERSION}/" \
		${WRKSRC}/mailnews/extensions/enigmail/Makefile.in

do-build:
.if ${GECKO_TARGET} == "configure"
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${MOZSRC} tier_base
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${MOZSRC} tier_nspr
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${MOZSRC} tier_js
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} export
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${MOZSRC}/modules/libreg
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${MOZSRC}/xpcom/string
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${MOZSRC}/xpcom
.if ${PORTVERSION} == "1.0.1"
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${MOZSRC}/xpcom/obsolete
.endif
.endif
	cd ${WRKSRC}/mailnews/extensions/enigmail && ./makemake -r
	cd ${WRKSRC}/mailnews/extensions/enigmail && ${SETENV} ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/mailnews/extensions/enigmail && ${SETENV} ${MAKE_ENV} ${GMAKE} xpi

do-install:
	@${MKDIR} ${XPI_LIBDIR}/${XPI_ID} ${XPI_LIBDIR}/symlinks/${GECKO}
	@(cd ${XPI_LIBDIR}/${XPI_ID}; /usr/bin/tar xf ${XPI_FILE})
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${XPI_ID}
	@${REINPLACE_CMD} -i "" "s/${XPI_ORIG_ID}/${XPI_ID}/" ${XPI_LIBDIR}/${XPI_ID}/install.rdf
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${XPI_ID}
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${LOCALBASE}/lib/${GECKO}/extensions 2>/dev/null || true
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${XPI_LIBDIR}/symlinks/${GECKO} 2>/dev/null || true
	@(cd ${XPI_LIBDIR}; ${FIND} ${XPI_ID} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} 'lib/xpi/symlinks/${GECKO}/${XPI_ID}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${LN} -sf %D/lib/xpi/${XPI_ID} ${LOCALBASE}/lib/${GECKO}/extensions 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/lib/${GECKO}/extensions/${XPI_ID}' >> ${TMPPLIST}
	@(cd ${XPI_LIBDIR}; ${FIND} ${XPI_ID} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks/${GECKO} 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi 2>/dev/null || true' >> ${TMPPLIST}

.include <bsd.port.post.mk>
