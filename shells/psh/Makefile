# New ports collection makefile for:	perlsh
# Date created:		11 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	perlsh
PORTVERSION=	0.007
CATEGORIES=	shells perl5
MASTER_SITES=	http://www.focusresearch.com/gregor/psh/
DISTNAME=	psh-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_PERL5=	yes
FETCH_BEFORE_ARGS+=	-t
MAKE_ENV+=	PPREFIX="${PREFIX}"
MAN1=		psh.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include "${.CURDIR}/files/man3"

do-build:
	@(cd ${WRKSRC} && ${PERL} Makefile.PL && ${MAKE})

post-install:  
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/psh /etc/shells.bak; \
	${ECHO} ${PREFIX}/bin/psh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
