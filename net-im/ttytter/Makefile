# New ports collection makefile for:	ttytter
# Date created:		21 March 2009
# Whom:			Julian C. Dunn <jdunn@aquezada.com>
#
# $FreeBSD$

PORTNAME=	ttytter
PORTVERSION=	1.2.02
CATEGORIES=	net-im perl5
MASTER_SITES=	http://www.floodgap.com/software/ttytter/dist1/
DISTNAME=	${PORTVERSION}
EXTRACT_SUFX=	.txt

MAINTAINER=	jdunn@aquezada.com
COMMENT=	Command-line Twitter client in Perl

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate

NO_BUILD=	yes
USE_PERL5_RUN=	yes

OPTIONS=	READLINE	"Include rich readline support" on \
		RLTTYTTER	"Use T::R::TTYtter readline driver (beta!)" off \

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if !defined(WITHOUT_READLINE)
RUN_DEPENDS+=	p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl
.endif

.if defined(WITH_RLTTYTTER)
RUN_DEPENDS+=	p5-ReadLine-TTYtter>=0:${PORTSDIR}/devel/p5-ReadLine-TTYtter
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}/${DISTFILES}

post-patch:
	@${REINPLACE_CMD} -e 's|^\#!/usr/bin/perl|\#!${PERL}|' ${WRKSRC}/${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTFILES} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
