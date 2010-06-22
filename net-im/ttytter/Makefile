# New ports collection makefile for:	ttytter
# Date created:				21 March 2009
# Whom:				        Julian C. Dunn <jdunn@aquezada.com>
#
# $FreeBSD$

PORTNAME=	ttytter
PORTVERSION=	1.0.4
CATEGORIES=	net-im
MASTER_SITES=	http://www.floodgap.com/software/ttytter/dist1/
DISTFILES=	1.0.04.txt
EXTRACT_ONLY=

MAINTAINER=	jdunn@aquezada.com
COMMENT=	Command-line Twitter client in Perl

RUN_DEPENDS=	${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		curl:${PORTSDIR}/ftp/curl

NO_BUILD=	yes
USE_PERL5_RUN=	yes

OPTIONS=	READLINE	"Include rich readline support"	on

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_READLINE)
RUN_DEPENDS+=	${SITE_PERL}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES}  ${WRKSRC}/${PORTNAME}-${PORTVERSION}.txt

post-patch:
	@${REINPLACE_CMD} -e 's|^\#!/usr/bin/perl|\#!${PERL}|' ${WRKSRC}/${PORTNAME}-${PORTVERSION}.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.txt ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
