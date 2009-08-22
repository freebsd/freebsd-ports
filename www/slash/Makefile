# New ports collection makefile for:	slash
# Date created:				18 March 2002
# Whom:					Autrijus Tang
#
# $FreeBSD$
#

PORTNAME=	slash
PORTVERSION=	2.2.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}code/${PORTNAME}code/${PORTVERSION}
DISTNAME=	slash-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Slash-Like Automatic Storytelling Homepage system

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/Bundle/Slash.pm:${PORTSDIR}/www/p5-Bundle-Slash
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl

USE_PERL5=	yes
USE_APACHE=	13

SUB_FILES+=	pkg-message

MAKE_ARGS+=	SLASH_PREFIX=${PREFIX}/slash

DOCS=		README INSTALL

CONFLICTS=	metalist

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		FZ.3 Slash.3 Slash::Apache.3 Slash::Apache::Banlist.3 \
		Slash::Apache::Log.3 Slash::Apache::User.3 \
		Slash::Custom::Bulkmail.3 Slash::DB.3 Slash::DB::MySQL.3 \
		Slash::DB::Oracle.3 Slash::DB::PostgreSQL.3 \
		Slash::DB::Static::MySQL.3 Slash::DB::Static::Oracle.3 \
		Slash::DB::Static::PostgreSQL.3 Slash::DB::Utility.3 \
		Slash::Display.3 Slash::Display::Plugin.3 \
		Slash::Display::Provider.3 Slash::Install.3 Slash::Journal.3 \
		Slash::Messages.3 Slash::Messages::DB::MySQL.3 \
		Slash::Search.3 Slash::Test.3 Slash::Utility.3 \
		Slash::Utility::Access.3 Slash::Utility::Anchor.3 \
		Slash::Utility::Data.3 Slash::Utility::Display.3 \
		Slash::Utility::Environment.3 Slash::Utility::System.3 \
		Slash::XML.3 Slash::XML::RSS.3

post-install:
	@${FIND} ${PREFIX}/slash -name "*.orig" -delete
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
