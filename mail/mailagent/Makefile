# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=		mailagent
PORTVERSION=		3.1.78
CATEGORIES=		mail
MASTER_SITES=		http://eron.info/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sophisticated automatic mail-processing tool

DEPRECATED=	Unmaintained interactive port
EXPIRATION_DATE=2014-08-20

USES=		perl5 tar:bzip2

NO_PACKAGE=	Correct FQDN needs to be hardcoded
IS_INTERACTIVE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-dres \
			-Dperlpath='${PERL}' \
			-Dccflags='${CFLAGS}' \
			-Dd_flockonly='define' \
			-Dutmp='/var/run/utmp' \
			-Dprefix='${PREFIX}' \
			-Dmansrc='${STAGEDIR}${PREFIX}/man/man1'
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV=	PATH=`dirname ${PERL5}`:${PATH} INSTALL_PREFIX=${STAGEDIR}
INSTALL_TARGET=	install install.man

.include <bsd.port.pre.mk>
.if ${OSVERSION} > 900006
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-utmpx-agent_pl_utmp_utmp.pl \
		${PATCHDIR}/extra-patch-utmpx-agent_pl_utmp_Makefile.SH
.endif

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
	  ${REINPLACE_CMD} -i '' -e 's|exec perl -S|exec ${PERL} -S|' \
	    agent/edusers.SH agent/magent.sh agent/maildist.SH \
	    agent/mailhelp.SH agent/maillist.SH agent/mailpatch.SH \
	    agent/package.SH agent/test/TEST agent/test/atail \
	    bin/perload misc/getcost/getcost misc/mime/unmime \
	    misc/news/newsgate)

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/misc
	${CP} -pR ${WRKSRC}/misc/* ${STAGEDIR}${EXAMPLESDIR}/misc
	@${LN} -fs ${PREFIX}/lib/mailagent/examples ${STAGEDIR}${EXAMPLESDIR}/agent

.include <bsd.port.post.mk>
