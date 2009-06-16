# New ports collection makefile for:   foomatic-db-engine
# Date created:			07 July 2003
# Whom:				Martin Ranne <gasp@ridcully.dnsalias.org>
#
# $FreeBSD$
#

PORTNAME=	engine
PORTVERSION=	4.0.1
PORTEPOCH=	2
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/foomatic/ \
		${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL:S,$,acm/foomatic/,}
PKGNAMEPREFIX=	foomatic-db-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	foomatic

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Foomatic database engine

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl

PROJECTHOST=	bsdistfiles
USE_GNOME=	libxml2
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL} LIBDIR=${PREFIX}/share/foomatic/

MAN1=		foomatic-printjob.1 foomatic-ppdfile.1 foomatic-perl-data.1 \
		foomatic-configure.1 foomatic-compiledb.1 foomatic-combo-xml.1 \
		foomatic-ppd-options.1
MAN8=		foomatic-preferred-driver.8 \
		foomatic-kitload.8 foomatic-getpjloptions.8 \
		foomatic-addpjloptions.8

post-patch:
	@${REINPLACE_CMD} -e \
		"s,sysconfdir=/etc,sysconfdir=\'${PREFIX}/etc\',g ; \
		 s,/usr/local/etc:,${PREFIX}/etc:,g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		"s,/usr/local/bin:,${PREFIX}/bin:,g" ${WRKSRC}/Makefile.in

post-install:
.for file in foomatic-combo-xml foomatic-perl-data
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
