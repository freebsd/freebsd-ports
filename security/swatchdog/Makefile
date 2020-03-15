# Created by: jfitz
# $FreeBSD$

PORTNAME=	swatchdog
PORTVERSION=	3.2.4
CATEGORIES=	security sysutils
MASTER_SITES=	SF/swatch/${PORTNAME}

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Simple log watcher formerly known as swatch

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-File-Tail>=0:devel/p5-File-Tail \
		p5-TimeDate>=0:devel/p5-TimeDate
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	INSTALLMAN1DIR=${PREFIX}/man/man1
USE_RC_SUBR=	${PORTNAME}

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
