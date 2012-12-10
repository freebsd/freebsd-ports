# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	synce
PORTVERSION=	0.7.5
PORTREVISION=	18
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	synce_plugin-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Windows CE addressbook plugin for Claws Mail

LICENSE=	GPLv3

LIB_DEPENDS=	rapi:${PORTSDIR}/palm/synce-librapi2
BUILD_DEPENDS=	claws-mail>=3.9.0:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=3.9.0:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf
MAKE_JOBS_SAFE=	yes

DEPRECATED=	No longer suppported by Claws Mail team
EXPIRATION_DATE=	2013-01-10
BROKEN=		Does not compile with claws-mail>=3.9.0

CONFIGURE_ARGS=	--with-libsynce=${LOCALBASE} \
		--with-librapi2=${LOCALBASE}

PLIST_FILES=	lib/claws-mail/plugins/synce_plugin.a \
		lib/claws-mail/plugins/synce_plugin.la \
		lib/claws-mail/plugins/synce_plugin.so

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|2.63|%%AUTOCONF_VERSION%%|g' ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
