# Created by: Masafumi NAKANE <max@FreeBSD.org>
# $FreeBSD$

PORTNAME=		mailagent
PORTVERSION=		3.1.78
PORTREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://eron.info/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sophisticated automatic mail-processing tool

USES=		perl5 tar:bzip2

ORGFILE=	${PREFIX}/etc/mailagent.orgname

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-dres \
			-Dperlpath='${PERL}' \
			-Dccflags='${CFLAGS}' \
			-Dd_flockonly='define' \
			-Dutmp='/var/run/utmp' \
			-Dorgname='${ORGFILE}' \
			-Dprefix='${PREFIX}' \
			-Dmansrc='${STAGEDIR}${PREFIX}/man/man1'
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV=	PATH=`dirname ${PERL}`:${PATH} INSTALL_PREFIX=${STAGEDIR}
INSTALL_TARGET=	install install.man

SUB_LIST+=	ORGFILE="${ORGFILE}"
SUB_FILES=	pkg-message
PLIST_SUB+=	ORGFILE="${ORGFILE}"

pre-extract:
	@if [ `${SH} -c umask` != 0022 ]; then \
	  ${ECHO} "Please set umask to 022 before running make,"; \
	  ${ECHO} "or mailagent will not build successfully."; \
	  ${FALSE}; fi

post-patch:
	@(cd ${WRKSRC}; \
	  ${REINPLACE_CMD} -i '' -e 's|exec perl -S|exec ${PERL} -S|' \
	    agent/edusers.SH agent/magent.sh agent/maildist.SH \
	    agent/mailhelp.SH agent/maillist.SH agent/mailpatch.SH \
	    agent/package.SH agent/test/TEST agent/test/atail \
	    bin/perload misc/getcost/getcost misc/mime/unmime \
	    misc/news/newsgate)

TEST_CMD=	'(cd ${WRKSRC}/agent/test; ${SETENV} ${MAKE_ENV} ${MAKE})'
do-test:
	@if [ `${ID} -u` = 0 ]; then \
	  ${CHOWN} -R nobody ${WRKSRC}/agent/test; \
	  su -m nobody -c ${TEST_CMD}; \
	else \
	  ${SH} -c ${TEST_CMD}; \
	fi

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/misc
	cd ${WRKSRC}/misc && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/misc
	${MV} ${STAGEDIR}${PREFIX}/lib/mailagent/examples ${STAGEDIR}${EXAMPLESDIR}/agent

.include <bsd.port.mk>
