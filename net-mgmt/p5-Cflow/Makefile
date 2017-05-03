# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	Cflow
PORTVERSION=	1.053
PORTREVISION=	2
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	http://net.doit.wisc.edu/~plonka/Cflow/ \
		http://net.doit.wisc.edu/~plonka/Cflow/old/
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	Analyze raw flow files written by cflowd (Cisco NetFlow data)

BUILD_DEPENDS=	${LOCALBASE}/lib/libft.a:net-mgmt/flow-tools
RUN_DEPENDS=	${LOCALBASE}/lib/libft.a:net-mgmt/flow-tools

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|\.\./\.\./lib|${LOCALBASE}/lib|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
