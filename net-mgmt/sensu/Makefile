# Created by: User %%FULLNAME%% <tomoyukis@gdb1.dcjp02.reallyenglish.com>
# $FreeBSD$

PORTNAME=	sensu
PORTVERSION= 0.23.2
PORTREVISION=	2
PORTEPOCH=	20160526
DISTVERSIONSUFFIX=	_${PORTREVISION}
CATEGORIES=	net-mgmt
# https://core.sensuapp.com/freebsd/10.2/amd64/sensu-0.23.2_2.txz
MASTER_SITES=	https://core.sensuapp.com/freebsd/10.2/amd64/

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Monitoring framework that aims to be simple, malleable, and scalable

EXTRACT_SUFX=	.txz
NO_BUILD=	yes
NO_TEST=	yes

do-install:
	${TAR} -cf - -C ${WRKDIR} usr var opt | ${TAR} -C ${STAGEDIR} -xf -

stage-qa:
	# disable qa as the way to install the package is so wrong

.include <bsd.port.mk>
