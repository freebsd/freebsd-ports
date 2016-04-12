# Created by: jfitz
# $FreeBSD$

PORTNAME=	swatch
PORTVERSION=	3.2.3
PORTREVISION=	3
CATEGORIES=	security sysutils
MASTER_SITES=	SF

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	The Simple WATCHer and filter

BUILD_DEPENDS=	\
	p5-TimeDate>=0:devel/p5-TimeDate \
	p5-Date-Manip>=0:devel/p5-Date-Manip \
	p5-Date-Calc>=0:devel/p5-Date-Calc \
	p5-File-Tail>=0:devel/p5-File-Tail
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	INSTALLMAN1DIR=${PREFIX}/man/man1
USE_RC_SUBR=	${PORTNAME}

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
