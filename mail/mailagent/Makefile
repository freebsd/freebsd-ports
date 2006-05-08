# New ports collection makefile for:	mailagent
# Date created:			23 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		mailagent
PORTVERSION=		3.0.73
PORTREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/RAM

MAINTAINER=	max@FreeBSD.org
COMMENT=	A sophisticated automatic mail-processing tool

USE_PERL5=	yes
NO_PACKAGE=	Correct FQDN needs to be hardcoded
IS_INTERACTIVE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-dres \
			-Dperlpath='${PERL}' \
			-Dccflags='${CFLAGS}' \
			-Dd_flockonly='define' \
			-Dutmp='/var/run/utmp' \
			-Dprefix='${PREFIX}' -Dmansrc='${PREFIX}/man/man1'
MAKE_ENV=	PATH=`dirname ${PERL5}`:${PATH}
INSTALL_TARGET=	install install.man

MAN1=		edusers.1 mailagent.1 package.1 mailhelp.1
MLINKS=		mailhelp.1 maildist.1  mailhelp.1 mailpatch.1 \
		mailhelp.1 maillist.1

pre-extract:
	@if [ `${SH} -c umask` != 0022 ]; then \
	  ${ECHO} "Please set umask to 022 before running make,"; \
	  ${ECHO} "or mailagent will not build successfully."; \
	  ${FALSE}; fi
	@if [ `id -u` = 0 ]; then \
	  ${ECHO} "Do not build mailagent as root or it won't pass the sanity tests."; \
	  ${FALSE}; fi

post-patch:
	@(cd ${WRKSRC}; \
	  ${PERL} -pi.bak \
	    -e 's|exec perl -S|exec ${PERL} -S|' \
	    agent/edusers.SH agent/magent.sh agent/maildist.SH \
	    agent/mailhelp.SH agent/maillist.SH agent/mailpatch.SH \
	    agent/package.SH agent/test/TEST agent/test/atail \
	    bin/perload misc/getcost/getcost misc/mime/unmime \
	    misc/news/newsgate)

post-install:
	@${MKDIR} ${EXAMPLESDIR}/misc
	${CP} -pR ${WRKSRC}/misc/* ${EXAMPLESDIR}/misc
	@${LN} -fs ${PREFIX}/lib/mailagent/examples ${EXAMPLESDIR}/agent

.include <bsd.port.mk>
