# New ports collection makefile for:	perlsh
# Date created:		11 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	perlsh
PORTVERSION=	1.8
CATEGORIES=	shells perl5
MASTER_SITES=	http://www.gregorpurdy.com/gregor/psh/
DISTNAME=	psh-${PORTVERSION}

MAINTAINER=	freebsd@galle.com.br
COMMENT=	New shell made entirely out of a Perl script

PERL_CONFIGURE=	yes

MAN1=	psh.1 pshcomplete.1 pshconfig.1 pshdevel.1

MAN3=	Psh::Completion.3 \
	Psh::Joblist.3 \
	Psh::Locale.3 \
	Psh::Locale::Default.3 \
	Psh::OS.3 \
	Psh::OS::Win.3 \
	Psh::Parser.3 \
	Psh::PerlEval.3 \
	Psh::Strategy.3 \
	Psh::StrategyBunch.3

pre-install:
	@${PERL} -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/Makefile;
	@${PERL} -pi -e "s:/usr/local/man/man1:${MAN3PREFIX}/man/man1:g" ${WRKSRC}/Makefile;
	@${PERL} -pi -e "s:/usr/local/lib/perl5/5.00503/man/man3:${MAN3PREFIX}/man/man3:g" ${WRKSRC}/Makefile;

post-install:
	@${ECHO_MSG} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/psh /etc/shells.bak; \
	${ECHO_CMD} ${PREFIX}/bin/psh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
