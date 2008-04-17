# New ports collection makefile for:	p5-Authen-Krb5
# Date created:				22 January 2001
# Whom:					ajk@iu.edu
#
# $FreeBSD$
#

PORTNAME=	Authen-Krb5
PORTVERSION=	1.6
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Krb5-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for Kerberos 5

LIB_DEPENDS=	gssapi_krb5.2:${PORTSDIR}/security/krb5

PERL_CONFIGURE=	yes

MAN3=		Authen::Krb5.3

KRB5_HOME?=	${LOCALBASE}

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e 's:/usr/local/krb5:${KRB5_HOME}:g; \
		         s:/usr/local:${LOCALBASE}:g;' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
