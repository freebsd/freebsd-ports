# New ports collection makefile for:	cmail
# Date created:		31 Dec 1998
# Whom:			Chip Marshall <chip@chocobo.cx>
#
# $FreeBSD$
#

PORTNAME=	cmail
PORTVERSION=	4.01
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.eboai.org/pub/users/chip/

MAINTAINER=	chip@chocobo.cx
COMMENT=	A simple mail counter, useful for multiple mailfiles

RUN_DEPENDS=	${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor

USE_BZIP2=	yes
PERL_CONFIGURE=	yes

MAN1=		cmail.1
DOCS=		LICENSE README

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cmail.rc ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
