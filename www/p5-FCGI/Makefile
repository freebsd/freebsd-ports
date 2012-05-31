# New ports collection makefile for:	p5-FCGI
# Date created:				October 27th 1999
# Whom:	      				Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	FCGI
PORTVERSION=	0.74
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules for perl5, for enabling FastCGI support in CGI scripts

OPTIONS_DEFINE=	PURE_PERL
PURE_PERL_DESC=	Build pure Perl version (experimental)

# XXX: fcgi.0 is missing FCGX_Detach, see ports/149755
#LIB_DEPENDS=	fcgi.0:${PORTSDIR}/www/fcgi
#CONFIGURE_ARGS+=	--use-installed=${LOCALBASE}

PERL_CONFIGURE=	yes

MAN3=		FCGI.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPURE_PERL}
CONFIGURE_ARGS+=--pure-perl
PLIST_SUB=	PURE_PERL="@comment "
.else
PLIST_SUB=	PURE_PERL=""
.endif

.include <bsd.port.mk>
