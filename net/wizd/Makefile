# New ports collection makefile for:	wizd
# Date created:		2008-06-25
# Whom:			Ayumi M <ayu@commun.jp>
#
# $FreeBSD$
#

PORTNAME=	wizd
PORTVERSION=	24
PORTREVISION=	2
CATEGORIES=	net multimedia
MASTER_SITES=	SF/${PORTNAME}/Sources/Sources%20v${PORTVERSION}
DISTFILES=	wizd_sources_v${PORTVERSION}.zip simplicity_v1-2.zip

MAINTAINER=	ayu@commun.jp
COMMENT=	An open-source media server for Syabas-based media players

LIB_DEPENDS=	dvdread:${PORTSDIR}/multimedia/libdvdread \
		jpeg:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	Makefile
USE_ZIP=	yes
USE_RC_SUBR=	wizd.sh

post-patch:
	@${REINPLACE_CMD} -e 's|./skin|${DATADIR}/skins|' ${WRKSRC}/wizd.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wizd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/wizd.conf ${PREFIX}/etc/wizd.conf.sample

	${MKDIR} ${DATADIR}/skins
.for DIR in simplicity simplicity_hires
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${DATADIR}/skins
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
