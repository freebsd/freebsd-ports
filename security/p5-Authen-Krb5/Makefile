# New ports collection makefile for:	p5-Authen-Krb5
# Date created:				22 January 2001
# Whom:					ajk@iu.edu
#
# $FreeBSD$
#

PORTNAME=	Authen-Krb5
PORTVERSION=	1.2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-
DISTNAME=	Krb5-${PORTVERSION}

MAINTAINER=	ajk@iu.edu

LIB_DEPENDS=	gssapi_krb5.2:${PORTSDIR}/security/krb5

PERL_CONFIGURE=	yes

MAN3=		Authen::Krb5.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

KRB5_HOME?=	${PREFIX}

post-patch:
	@${PERL} -pi -e 's:/usr/local/krb5:${KRB5_HOME}:g' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
