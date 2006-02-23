# New ports collection makefile for:	verlihub
# Date created:				2 April 2004
# Whom:					Hurbold
#
# $FreeBSD$
#

PORTNAME=	verlihub
PORTVERSION=	0.9.8.c
PORTEPOCH=	1
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	verlihub
DISTNAME=	verlihub-0.9.8c-RC2

MAINTAINER=	hurbold@yahoo.com
COMMENT=	Verlihub Linux/Unix Direct Connect Hub Software

LIB_DEPENDS=	GeoIP.4:${PORTSDIR}/net/GeoIP \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

WRKSRC=		${WRKDIR}/verlihub-0.9.8c

USE_MYSQL=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

PKGMESSAGE=	${WRKDIR}/pkg-message
PORTDOCS=	configuring.txt help.sql using.txt features.html help.html params.php verlihub.html

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.4+
.endif

post-patch:
	@${CAT} ${PKGDIR}/pkg-message | ${SED} 's|%%PREFIX%%|${PREFIX}|' > ${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
