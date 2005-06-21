# New ports collection makefile for:	quickml
# Date created:				11 June 2004
# Whom:					Yuichiro AIZAWA <yaizawa@mdbl.sfc.keio.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	quickml
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://namazu.org/%7esatoru/quickml/

MAINTAINER=	yaizawa@mdbl.sfc.keio.ac.jp
COMMENT=	An easy-to-use mailing list system

OPTIONS+=	ANALOG "Enable quickml-analog" on \
		LIMIT  "Enable Creators and Members Limitation Patch" off

PKGINSTALL=	${WRKDIR}/pkg-install

QUICKML_USER=	quickml
QUICKML_GROUP=	quickml

USE_AUTOCONF_VER=	259
GNU_CONFIGURE=	yes
USE_RUBY=	yes

USE_RC_SUBR=	yes
FILES_SUB=	USER=${QUICKML_USER} GROUP=${QUICKML_GROUP} \
		PREFIX=${PREFIX} RC_SUBR=${RC_SUBR} RUBY=${RUBY}

CONFIGURE_ARGS+=	--datadir="${PREFIX}/share/quickml"
CONFIGURE_ARGS+=	--with-ruby="${RUBY}"
CONFIGURE_ARGS+=	--with-user="${QUICKML_USER}"
CONFIGURE_ARGS+=	--with-group="${QUICKML_GROUP}"
CONFIGURE_ARGS+=	--with-rubydir="${RUBY_LIBDIR}"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LIMIT)
PATCH_DIST_STRIP=	-p1
.endif

.if !defined(WITHOUT_ANALOG)
USE_GHOSTSCRIPT_RUN=	yes
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot \
		convert:${PORTSDIR}/graphics/ImageMagick
.endif

post-fetch:
.if !defined(WITHOUT_LIMIT)
	@ ( cd ${DISTDIR} && ${FETCH_CMD} -o ${PORTNAME}-${PORTVERSION}-limited.patch "http://linux.matchy.net/view.xcg?c=plugin;plugin=attach_download;p=QuickMLLimited;file_name=${PORTNAME}-${PORTVERSION}-limited.patch" )
.endif

post-patch:
.if !defined(WITHOUT_LIMIT)
	@${PATCH} ${PATCH_DIST_ARGS} < ${DISTDIR}/${PORTNAME}-${PORTVERSION}-limited.patch
.endif
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/quickml.sh > ${WRKDIR}/quickml.sh
.if defined(WITHOUT_ANALOG)
	${PATCH} ${PATCH_DIST_ARGS} < ${FILESDIR}/without_quickml-analog
.endif

pre-install:
	@${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-install > ${PKGINSTALL}
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/messages.ja ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ml-usage.en.rd ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/quickml.en.rd ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/quickml.ja.rd ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/with-mta.en.rd ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/with-mta.ja.rd ${DOCSDIR}
.endif
.if !exists(${PREFIX}/etc/rc.d/quickml.sh)
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/quickml.sh startup file."
	${INSTALL_SCRIPT} -m 751 ${WRKDIR}/quickml.sh ${PREFIX}/etc/rc.d/quickml.sh
.endif
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' -e 's|%%DOCSDIR%%|${DOCSDIR}|g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
