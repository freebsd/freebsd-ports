# Created by: Patrick MARIE <mycroft@virgaria.org>
# $FreeBSD$

PORTNAME=	proxychains
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/version%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Redirect connection through proxy servers

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's!$$(srcdir)/proxychains.conf!$$(srcdir)/proxychains.conf.sample!' \
		-e 's!libproxychains_la_LIBADD = -ldl!libproxychains_la_LIBADD =!' \
		${WRKSRC}/proxychains/Makefile.in
	@${MV} ${WRKSRC}/proxychains/proxychains.conf \
		${WRKSRC}/proxychains/proxychains.conf.sample

post-configure:
	@${ECHO_CMD} '#define PREFIX "${PREFIX}"' >> ${WRKSRC}/config.h

post-install:
	@[ -f ${PREFIX}/etc/proxychains.conf ] || ${CP} ${PREFIX}/etc/proxychains.conf.sample \
		${PREFIX}/etc/proxychains.conf

.include <bsd.port.mk>
