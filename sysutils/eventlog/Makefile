# Created by: Ivan Lago <ivan.lago@ifom-ieo-campus.it>
# $FreeBSD$

PORTNAME=	eventlog
PORTVERSION=	0.2.12
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/sources/3.2.2/source/
DISTFILES=	${PORTNAME}_${PORTVERSION}.tar.gz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Replacement of the simple syslog() API providing structure to messages

#	Reminder: Retire this port sysutils/syslog-ng310 is retired.
#	syslog-ng311 and subsequent ports make use of a private copy of
#	eventlog. sysutils/syslog-ng* is this port's only consumer.

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
