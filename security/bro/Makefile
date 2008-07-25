# Ports collection makefile for:  bro
# Date created:			  Sat Feb 28, 1998
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	bro
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://bro-ids.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-stable

MAINTAINER=	pauls@utdallas.edu
COMMENT=	System for detecting Network Intruders in real-time

CONFLICTS=	sysutils/lbl-cf-1.* sysutils/lbl-hf-1.*

OPTIONS=	GPG "Support encrypted email" Off \
		DOCS "Install documentation (not recommended)" Off

WRKSRC=		${WRKDIR}/bro-${PORTVERSION}.1

USE_BISON=	build
USE_LDCONFIG=	${PREFIX}/share
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
USE_PERL5=	yes

IS_INTERACTIVE=	yes	# during the install phase

SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST=	BROHOME=${BROHOME} BROSITEDIR=${BROSITEDIR} SITE_PERL=${SITE_PERL} WRKSRC=${WRKSRC}
BROHOME=	${PREFIX}/bro
BROSITEDIR=	${BROHOME}/site

.include <bsd.port.pre.mk>

.if defined(WITH_GPG)
BUILD_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
.endif
.if !defined(WITH_DOCS)
NOPORTDOCS=	Yes
.endif

post-extract:
	@cd ${WRKSRC}/src && ${TAR} xfz libedit.src.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS+=-g -O0||g; \
		s|CC=gcc||' \
		${WRKSRC}/src/libedit/Makefile.in \
		${WRKSRC}/src/libedit/Makefile
	@${REINPLACE_CMD} -e "s,tr '\[a-z\]' '\[A-Z\]',tr 'a-z' 'A-Z',g" \
		${WRKSRC}/src/libedit/makelist
	@${REINPLACE_CMD} -E -e 's,(const char\*) const (helpstring),\1 \2,g' \
		${WRKSRC}/src/DebugCmds.h

pre-configure:
	@${ECHO_CMD} "Configure libedit..."
	@(cd ${WRKSRC}/src/libedit && ${MAKE_ENV} ./configure)

pre-build:
	@${ECHO_CMD} "Building libedit..."
	@(cd ${WRKSRC}/src/libedit && ${MAKE})

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/bro
	@${MKDIR} ${PREFIX}/bro/etc
	@${MKDIR} ${SITE_PERL}/mach/Bro
	@${MKDIR} ${SITE_PERL}/mach/Bro/Log
	@${MKDIR} ${SITE_PERL}/mach/Bro/Report
	${INSTALL_DATA} ${WRKSRC}/scripts/bro.cfg.example ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/scripts/local.site.bro.default ${BROSITEDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/IP4.pm ${SITE_PERL}/mach
	${INSTALL_DATA} ${WRKSRC}/scripts/perl/lib/Bro/Config.pm ${SITE_PERL}/mach/Bro
	${INSTALL_DATA} ${WRKSRC}/scripts/perl/lib/Bro/Log.pm ${SITE_PERL}/mach/Bro
	${INSTALL_DATA} ${WRKSRC}/scripts/perl/lib/Bro/Report.pm ${SITE_PERL}/mach/Bro
	${INSTALL_DATA} ${WRKSRC}/scripts/perl/lib/Bro/Signature.pm ${SITE_PERL}/mach/Bro
	${INSTALL_DATA} ${WRKSRC}/scripts/perl/lib/Bro/Log/Alarm.pm ${SITE_PERL}/mach/Bro/Log
	${INSTALL_DATA} ${WRKSRC}/scripts/perl/lib/Bro/Log/Conn.pm ${SITE_PERL}/mach/Bro/Log
	${INSTALL_DATA} ${WRKSRC}/scripts/perl/lib/Bro/Report/Alarm.pm ${SITE_PERL}/mach/Bro/Report
	${INSTALL_DATA} ${WRKSRC}/scripts/perl/lib/Bro/Report/Conn.pm ${SITE_PERL}/mach/Bro/Report
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/bro.rc ${BROHOME}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/bro.rc-hooks.sh ${BROHOME}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/bro_config ${BROHOME}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/localnetMAC.pl ${BROHOME}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/perl/script/edit-brorule.pl ${BROHOME}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/perl/script/site-report.pl ${BROHOME}/scripts
	${INSTALL_PROGRAM} ${WRKSRC}/aux/adtrace/adtrace ${PREFIX}/bin
	${SH} ${PKGINSTALL}

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "You have chosen to install documentation"
	@${ECHO_MSG} "but the online documentation will be much"
	@${ECHO_MSG} "more up to date."
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/quick-start/Bro-quick-start.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/quick-start/bro-deployment.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/user-manual/Bro-user-manual.pdf ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
