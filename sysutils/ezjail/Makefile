# $FreeBSD$

PORTNAME=	ezjail
PORTVERSION=	3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://erdgeist.org/arts/software/ezjail/

MAINTAINER=	erdgeist@erdgeist.org
COMMENT=	Framework to easily create, manipulate, and run FreeBSD jails

USE_BZIP2=	yes

MAN5=		ezjail.conf.5
MAN7=		ezjail.7
MAN8=		ezjail-admin.8

NO_STAGE=	yes
post-install:
	[ -f ${PREFIX}/etc/${PORTNAME}.conf ] || \
		${CP} -p ${PREFIX}/etc/${PORTNAME}.conf.sample \
			 ${PREFIX}/etc/${PORTNAME}.conf

.include <bsd.port.mk>
