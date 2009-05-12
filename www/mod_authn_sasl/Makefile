# New ports collection makefile for:   	mod_authn_sasl
# Date created:        			February 16, 2009
# Whom:                			Joerg Pulz <Joerg.Pulz@frm2.tum.de>
#
# $FreeBSD$
#

PORTNAME=	mod_authn_sasl
PORTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/g}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows user authentication based on libsasl2 mechanisms on apache 2.2

LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2

FETCH_BEFORE_ARGS=	-v -v

USE_APACHE=	22
USE_BZIP2=	yes
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
#SHORTMODNAME=	authn_sasl

OPTIONS=	SASLAUTHD	"Register dependency for cyrus-sasl2-saslauthd"	off

PORTDOCS=	AUTHORS LICENSE

.include <bsd.port.pre.mk>

.if defined(WITH_SASLAUTHD)
RUN_DEPENDS+=	saslauthd:${PORTSDIR}/security/cyrus-sasl2-saslauthd
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.post.mk>
