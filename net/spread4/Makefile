# New ports collection makefile for:	spread
# Date created:		11 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	spread
PORTVERSION=	3.17.2
CATEGORIES=	net perl5
MASTER_SITES=	http://www.cnds.jhu.edu/download/noformdown/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	joshua@roughtrade.net
COMMENT=	The Spread Group Communication System, a network toolkit

WRKSRC=		${WRKDIR}/${PORTNAME}_src-${PORTVERSION}
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAN1=	spflooder.1 spmonitor.1 spread.1 sptuser.1 spuser.1
MAN3=	libsp.3 SP_connect.3 SP_disconnect.3 SP_equal_group_ids.3 SP_error.3 \
	SP_join.3 SP_leave.3 SP_multicast.3 SP_multigroup_multicast.3 \
	SP_multigroup_scat_multicast.3 SP_poll.3 SP_receive.3 \
	SP_scat_multicast.3 SP_scat_receive.3

USE_PERL5=	yes
USE_RC_SUBR=	yes
INSTALLS_SHLIB=	yes
PKGMESSAGE=	${WRKSRC}/license.txt

MAKE_ARGS+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

.if !defined(NOPORTDOCS)
PORTDOCS+=	Readme.txt LICENSE
.endif

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

.include <bsd.port.pre.mk>

# bsd.port.mk doesn't allow us to use GNU_CONFIGURE and PERL_CONFIGURE together.

PERL_CONFIGURE_ARGS=	CC="${CC}" CCFLAGS="${CFLAGS}" PREFIX="${PREFIX}" \
		INSTALLPRIVLIB="${PREFIX}/lib" INSTALLARCHLIB="${PREFIX}/lib"

_MANPAGES+=	${PREFIX}/lib/perl5/${PERL_VERSION}/man/man3/Spread.3

post-configure:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/docs/spread.1 ${WRKSRC}/docs/spmonitor.1

post-build:
	@cd ${WRKSRC}/perl/Spread && \
		${SETENV} ${CONFIGURE_ENV} ${PERL5} ./Makefile.PL ${PERL_CONFIGURE_ARGS}
	@cd ${WRKSRC}/perl/Spread && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile
	@cd ${WRKSRC}/perl/Spread && ${MAKE}
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/spread.sh > ${WRKDIR}/spread.sh

pre-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/spread.sh ${PREFIX}/etc/rc.d/spread.sh
	${INSTALL_DATA} ${WRKSRC}/sp.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sp_func.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sp_events.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf ${PREFIX}/etc/spread.conf.sample
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip ${PREFIX}/etc/spread.access_ip.sample
	(cd ${WRKSRC}/perl/Spread && ${MAKE} install)
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	${INSTALL} -d -o root -g wheel -m 0755 ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}/LICENSE
	${INSTALL_SCRIPT} ${WRKSRC}/perl/Spread/test.pl ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
