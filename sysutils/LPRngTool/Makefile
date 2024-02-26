PORTNAME=	LPRngTool
PORTVERSION=	1.3.2
PORTREVISION=	12
CATEGORIES=	sysutils print
MASTER_SITES=	SF/lprng/lprngtool/LRPngTool-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configuration Tool for LPRng
WWW=		https://lprng.sourceforge.net/

LICENSE=	GPLv2

BUILD_DEPENDS=	a2ps:print/a2ps \
		mpage:print/mpage

USES=		ghostscript:build tar:tgz tk
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	ac_cv_path_WISH=${WISH}
CONFIGURE_ARGS=	--with-spool_directory=/var/spool/lpd
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|=freebsd|=generic|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/cp $$p.sample $$p;/d ; \
		 /chmod 644 $$p;/d' ${WRKSRC}/postinstall.generic.sh

.include <bsd.port.mk>
