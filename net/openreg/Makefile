# New ports collection makefile for:	openreg
# Date created:				6 June 2003
# Whom:					seanc
#
# $FreeBSD$
#

PORTNAME=	openreg
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	openreg

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Domain Registry software

RUN_DEPENDS=	${LOCALBASE}/sbin/stunnel:${PORTSDIR}/security/stunnel \
		${LOCALBASE}/sbin/named:${PORTSDIR}/dns/bind9 \
		${LOCALBASE}/bin/postgres:${PORTSDIR}/${POSTGRESQL_PORT} \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
BUILD_DEPENDS=	${LOCALBASE}/include/isc/buffer.h:${PORTSDIR}/dns/bind9
LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

POSTGRESQL_PORT?=	databases/postgresql7

USE_OPENSSL=	YES
USE_PERL5=	YES
GNU_CONFIGURE=	YES
PERL_LEVEL=	500800

BROKEN=		Broken pkg-plist

post-install:
	@${MKDIR} ${DOCSDIR} ;\
	${CP} -r ${WRKSRC}/doc/ ${DOCSDIR} ;\
	cd ${WRKSRC}/doc ;\
	for file in `${FIND} ./ ! -type d` ; do \
		printf "share/doc/${PORTNAME}/%s\n" $$file >> ${TMPPLIST} ;\
	done ;\
	for dir in `${FIND} ./ -type d -mindepth 1| ${SORT} -r` ; do \
		printf "@dirrm share/doc/${PORTNAME}/%s\n" $$dir >> ${TMPPLIST} ;\
	done
	@${ECHO} "@dirrm share/doc/${PORTNAME}" >> ${TMPPLIST}
	@${CAT} pkg-message

.include <bsd.port.mk>
