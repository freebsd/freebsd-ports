# Created by: ajk@iu.edu
# $FreeBSD$

PORTNAME=	Authen-Krb5
PORTVERSION=	1.9
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Krb5-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for Kerberos 5

LIB_DEPENDS=	krb5.3:${PORTSDIR}/security/krb5

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
