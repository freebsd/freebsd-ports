# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flent
PORTVERSION=	1.2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net
MASTER_SITES=	GH \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	FLExible Network Tester

LICENSE=	GPLv3

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	fping>0:net/fping \
		iperf>0:benchmarks/iperf \
		netperf>0:benchmarks/netperf

USES=		desktop-file-utils python:2.7 shared-mime-info
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	tohojo
NO_ARCH=	yes

OPTIONS_DEFINE=		MATPLOT
MATPLOT_DESC=		Plot results using matplotlib (requires X)
MATPLOT_RUN_DEPENDS=	py-matplotlib>0:math/py-matplotlib

.include <bsd.port.options.mk>

.include <bsd.port.mk>
