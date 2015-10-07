# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GSSAPI
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN/LWP/AGROLMS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension providing access to the GSSAPIv2 library

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFAULT=	GSSAPI_BASE
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT

GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSSAPI_MIT}
KRB5CONF=	${KRB5_HOME}/bin/krb5-config
.else
KRB5CONF=	${HEIMDAL_HOME}/bin/krb5-config
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%KRB5CONF%%|${KRB5CONF}|g' \
	    ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
