# Created by: Peter Czanik <czanik@balabit.hu>
# $FreeBSD$

PORTNAME=	syslog-ng-incubator
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://packages.madhouse-project.org/syslog-ng/incubator/
DISTFILES=	syslog-ng-incubator-${PORTVERSION}.tar.xz
PKGNAMESUFFIX=	03

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The syslog-ng module incubator

DEPRECATED=	EOL, no longer supported by bababit.hu
EXPIRATION_DATE=	2016-06-30

WRKSRC=		$(WRKDIR)/$(PORTNAME)-$(PORTVERSION)

MAKE_JOBS_UNSAFE=	yes

LIB_DEPENDS=	libevtlog.so:sysutils/eventlog \
		libsyslog-ng-3.5.6.so:sysutils/syslog-ng35

USES=		bison gmake libtool lua pathfix pkgconfig shebangfix tar:xz
SHEBANG_FILES=	scl/elasticsearch/es-bridge
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_AUTOTOOLS=	autoconf:env

CONFIGURE_ARGS=	--datadir=${PREFIX}/share/syslog-ng/

.include <bsd.port.mk>
