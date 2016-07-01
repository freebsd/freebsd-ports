# Created by: Denis Shaposhnikov <dsh@bamus.cz>
# $FreeBSD$

PORTNAME=	dovecot2-antispam-plugin
PORTVERSION=	20130429
PORTREVISION=	19
CATEGORIES=	mail
MASTER_SITES=	http://olgeni.olgeni.com/~olgeni/distfiles/ \
		LOCAL/olgeni
DISTNAME=	dovecot-antispam-plugin-${DISTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Dovecot 2.x plugin for spam systems training

LICENSE=	GPLv2

BUILD_DEPENDS=	dovecot2>=2.2.0:mail/dovecot2 \
		gawk:lang/gawk
RUN_DEPENDS=	dovecot2>=2.2.0:mail/dovecot2

CONFLICTS=	dovecot-antispam-1.*
WRKSRC=		${WRKDIR}/dovecot-antispam-plugin-5ebc6aae4d7c

USES=		gmake tar:bzip2
USE_AUTOTOOLS=	aclocal autoheader autoconf
USE_LDCONFIG=	${PREFIX}/lib/dovecot

ACLOCAL_ARGS=	-I m4

PLIST_FILES=	lib/dovecot/lib90_antispam_plugin.so \
		man/man7/dovecot-antispam.7.gz

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/lib/ -name \*.so | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
