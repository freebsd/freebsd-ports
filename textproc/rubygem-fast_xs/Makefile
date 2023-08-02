PORTNAME=	fast_xs
PORTVERSION=	0.8.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Systems integration framework. Expander
WWW=		http://fast-xs.rubyforge.org/

LICENSE=	MIT

USES=		gem

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
