# New ports collection makefile for:	verlihub
# Date created:				2 April 2004
# Whom:					Hurbold
#
# $FreeBSD$
#

PORTNAME=	verlihub
PORTVERSION=	0.9.7
PORTREVISION=	
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= 	verlihub

MAINTAINER=	hurbold@yahoo.com
COMMENT=	Verlihub Linux/Unix Direct Connect Hub Software

LIB_DEPENDS=	GeoIP.4:${PORTSDIR}/net/GeoIP \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

USE_MYSQL=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lssl -lcrypto"

PKGMESSAGE=	${WRKDIR}/pkg-message
PORTDOCS=	configuring.txt help.sql using.txt features.html help.html params.php verlihub.html

post-patch:
	@${CAT} ${PKGDIR}/pkg-message | ${SED} 's|%%PREFIX%%|${PREFIX}|' > ${PKGMESSAGE}
	@${REINPLACE_CMD} -e "s|/bin/bash|/usr/local/bin/bash|" ${WRKSRC}/scripts/install \
	${WRKSRC}/scripts/regnick ${WRKSRC}/scripts/runhub ${WRKSRC}/scripts/trigger

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/verlihub_config ${LOCALBASE}/bin
	${MKDIR} ${EXAMPLESDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/trigger ${EXAMPLESDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/install ${EXAMPLESDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/regnick ${EXAMPLESDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/runhub ${EXAMPLESDIR}/scripts
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502010
USE_GCC=	3.3
.endif

.include <bsd.port.post.mk>
