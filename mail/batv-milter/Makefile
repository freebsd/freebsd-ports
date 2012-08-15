# New ports collection makefile for:	batv-milter
# Date created:		2009-06-04
# Whom:			Hirohisa Yamaguchi <umq@ueo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	batv-milter
PORTVERSION=	0.5.0
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	umq@ueo.co.jp
COMMENT=	A milter for BATV (Bounce Address Tag Validation)

USE_RC_SUBR=	milter-batv
USE_OPENSSL=	TRUE

WCONF=		${WRKSRC}/devtools/Site
MAN8=		batv-filter.8
PLIST_FILES=	bin/batv-filter
PORTDOCS=	INSTALL KNOWNBUGS LICENSE README RELEASE_NOTES \
		draft-levine-smtp-batv-01.txt

SITE=		${FILESDIR}/site.config.m4
SITE_SUB=	-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%OPENSSLINC%%|${OPENSSLINC}|g" \
		-e "s|%%OPENSSLLIB%%|${OPENSSLLIB}|g"

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_DEBUG)
SITE_SUB+=	-e '\|confOPTIMIZE.*-g|s/^dnl //g'
.endif

pre-configure:
	${SED} ${SITE_SUB} -e '\|^dnl |d' -e '/^dnl$$/d' \
		${SITE} > ${WCONF}/site.config.m4

post-install:
.if !defined(WITH_DEBUG)
	@${STRIP_CMD} ${PREFIX}/bin/batv-filter
.endif
.for i in ${MAN8}
	@${RM} -f ${MANPREFIX}/man/cat8/${i} ${MANPREFIX}/man/cat8/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man8/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
