# New ports collection makefile for:	perlsh
# Date created:		11 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	perlsh
PORTVERSION=	0.009
PORTREVISION=	1
CATEGORIES=	shells perl5
MASTER_SITES=	http://www.focusresearch.com/gregor/psh/
DISTNAME=	psh-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	New shell made entirely out of a Perl script

PERL_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Psh::Builtins.3 \
	Psh::Completion.3 \
	Psh::Job.3 \
	Psh::Joblist.3 \
	Psh::Locale::Base.3 \
	Psh::Locale::Default.3 \
	Psh::Locale::French.3 \
	Psh::Locale::German.3 \
	Psh::Locale::Italian.3 \
	Psh::Locale::Portuguese.3 \
	Psh::Locale::Spanish.3 \
	Psh::OS.3 \
	Psh::OS::Mac.3 \
	Psh::OS::Unix.3 \
	Psh::OS::Win.3 \
	Psh::PCompletion.3 \
	Psh::Parser.3 \
	Psh::PerlEval.3 \
	Psh::Util.3

pre-install:
	${REINPLACE_CMD} -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/Makefile;
	${REINPLACE_CMD} -e "s:/usr/local/man/man1:${MAN3PREFIX}/man/man1:g" ${WRKSRC}/Makefile;
	${REINPLACE_CMD} -e "s:/usr/local/lib/perl5/5.00503/man/man3:${MAN3PREFIX}/man/man3:g" ${WRKSRC}/Makefile;

post-install:
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/psh /etc/shells.bak; \
	${ECHO_CMD} ${PREFIX}/bin/psh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
