# New ports collection makefile for:	verlihub
# Date created:				2 April 2004
# Whom:					Hurbold
#
# $FreeBSD$
#

PORTNAME=	verlihub
PORTVERSION=	0.9.8.a
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	verlihub
DISTNAME=	verlihub-0.9.8a

MAINTAINER=	hurbold@yahoo.com
COMMENT=	Verlihub Linux/Unix Direct Connect Hub Software

LIB_DEPENDS=	GeoIP.4:${PORTSDIR}/net/GeoIP \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

USE_MYSQL=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

PKGMESSAGE=	${WRKDIR}/pkg-message
PORTDOCS=	configuring.txt help.sql using.txt features.html help.html params.php verlihub.html

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502010
USE_GCC=	3.3
.endif

.if ${OSVERSION} >= 502126
BROKEN=		Does not compile with gcc 3.4
.endif

.include <bsd.port.post.mk>
