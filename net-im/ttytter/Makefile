# New ports collection makefile for:	ttytter
# Date created:		21 March 2009
# Whom:			Julian C. Dunn <jdunn@aquezada.com>
#
# $FreeBSD$

PORTNAME=	ttytter
PORTVERSION=	2.1.00
CATEGORIES=	net-im perl5
MASTER_SITES=	http://www.floodgap.com/software/ttytter/dist2/:dist \
		http://www.floodgap.com/software/ffsl/:license
DISTFILES=	${PORTVERSION}.txt:dist license.txt:license
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jdunn@aquezada.com
COMMENT=	Command-line Twitter client in Perl

LICENSE=	FFSL
LICENSE_NAME=	Floodgap Free Software License
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate

NO_BUILD=	yes
USE_PERL5_RUN=	yes

OPTIONS_DEFINE=	READLINE RLTTYTTER
OPTIONS_DEFAULT=READLINE
READLINE_DESC=	Include rich readline support
RLTTYTTER_DESC=	Use T::R::TTYtter readline driver (beta!)

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE}
RUN_DEPENDS+=	p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl
.endif

.if ${PORT_OPTIONS:MRLTTYTTER}
RUN_DEPENDS+=	p5-ReadLine-TTYtter>=1.4:${PORTSDIR}/devel/p5-ReadLine-TTYtter
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${PORTVERSION}.txt ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/license.txt ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|^\#!/usr/bin/perl|\#!${PERL}|' ${WRKSRC}/${PORTVERSION}.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTVERSION}.txt ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
