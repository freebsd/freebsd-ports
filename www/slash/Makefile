# New ports collection makefile for:	slash
# Date created:				18 March 2002
# Whom:					Autrijus Tang
#
# $FreeBSD$
#

PORTNAME=	slash
PORTVERSION=	2.2.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	slashcode

MAINTAINER=	autrijus@autrijus.org

BUILD_DEPENDS=	${LOCALBASE}/bin/safe_mysqld:${PORTSDIR}/databases/mysql323-server \
		${SITE_PERL}/Bundle/Slash.pm:${PORTSDIR}/www/p5-Bundle-Slash
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

DOCS=		README INSTALL

post-install:
	@${SED} s!%%LOCALBASE%%!${LOCALBASE}!g ${PKGMESSAGE}

.include <bsd.port.mk>
