# New ports collection makefile for:	p5-Authen-Krb5
# Date created:				22 January 2001
# Whom:					ajk@iu.edu
#
# $FreeBSD$
#

PORTNAME=	Authen-Krb5
PORTVERSION=	1.5
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-
DISTNAME=	Krb5-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Perl extension for Kerberos 5

LIB_DEPENDS=	gssapi_krb5.2:${PORTSDIR}/security/krb5

#WRKSRC=		${WRKDIR}/${PORTNAME}

PERL_CONFIGURE=	yes

MAN3=		Authen::Krb5.3

KRB5_HOME?=	${PREFIX}

post-patch:
	@${PERL} -pi -e 's:${LOCALBASE}/krb5:${KRB5_HOME}:g' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
