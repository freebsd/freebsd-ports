# Created by: Denis Shaposhnikov <dsh@bamus.cz>
# $FreeBSD$

PORTNAME=	dovecot2-antispam-plugin
PORTVERSION=	20130429
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://olgeni.olgeni.com/~olgeni/distfiles/ \
		LOCAL/olgeni
DISTFILES=	dovecot-antispam-plugin-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Dovecot 2.x plugin for spam systems training

BUILD_DEPENDS=	dovecot>=2.2.0:${PORTSDIR}/mail/dovecot2 \
		gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	dovecot>=2.2.0:${PORTSDIR}/mail/dovecot2

CONFLICTS=	dovecot-antispam-1.*
WRKSRC=		${WRKDIR}/dovecot-antispam-plugin-5ebc6aae4d7c

USES=		gmake
USE_AUTOTOOLS=	aclocal autoheader autoconf
USE_BZIP2=	yes
USE_LDCONFIG=	${PREFIX}/lib/dovecot

ACLOCAL_ARGS=	-I m4

PLIST_FILES=	lib/dovecot/lib90_antispam_plugin.so \
		man/man7/dovecot-antispam.7.gz
PLIST_DIRSTRY=	lib/dovecot

.include <bsd.port.mk>
