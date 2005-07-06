# New ports collection makefile for:	colordiff
# Date created:				6 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	colordiff
PORTVERSION=	1.0.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A tool to colorize diff output

USE_PERL5=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

PLIST_DIRS=	%%EXAMPLESDIR%%
PLIST_FILES=	bin/colordiff %%EXAMPLESDIR%%/colordiffrc
MAN1=		colordiff.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500806
IGNORE=		needs Perl 5.8.6 or above (lang/perl5.8)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/perl|${PERL}|' \
		${WRKSRC}/${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/colordiffrc ${EXAMPLESDIR}

.include <bsd.port.post.mk>
