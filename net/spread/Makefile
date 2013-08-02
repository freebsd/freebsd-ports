# New ports collection makefile for:	spread
# Date created:		11 June 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	spread
PORTVERSION=	3.17.4
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	http://www.edu-linux.org/down/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Spread Group Communication System, a network toolkit

MAKE_JOBS_UNSAFE=	yes

PORTSCOUT=	limit:^3

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	spread
USE_LDCONFIG=	yes

USERS=		spread
GROUPS=		spread
RUNDIR=		/var/run/spread

PLIST_SUB+=	USERS=${USERS} GROUPS=${GROUPS} RUNDIR=${RUNDIR}

MAKE_ARGS+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}
WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}

PKGMESSAGE=	${WRKSRC}/license.txt
PORTDOCS=	Readme.txt LICENSE
HEADERFILES=	sp_func.h sp_func.h sp_events.h
MAN1=		spflooder.1 spmonitor.1 spread.1 sptuser.1 spuser.1
MAN3=		libsp.3 SP_connect.3 SP_disconnect.3 SP_equal_group_ids.3 \
		SP_error.3 SP_join.3 SP_leave.3 \
		SP_multicast.3 SP_multigroup_multicast.3 \
		SP_multigroup_scat_multicast.3 SP_poll.3 SP_receive.3 \
		SP_scat_multicast.3 SP_scat_receive.3

.include <bsd.port.pre.mk>

USES=		perl5
USE_PERL5=	configure
USES=		perl5
USE_PERL5=	configure
			INSTALLPRIVLIB="${PREFIX}/lib" INSTALLARCHLIB="${PREFIX}/lib"

_MANPAGES+=	${PREFIX}/lib/perl5/${PERL_VER}/man/man3/Spread.3

post-configure:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/docs/${PORTNAME}.1 ${WRKSRC}/docs/spmonitor.1

post-build:
	@cd ${WRKSRC}/perl/Spread && \
USES=		perl5
USE_PERL5=	configure
	@cd ${WRKSRC}/perl/Spread && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile
	@cd ${WRKSRC}/perl/Spread && ${MAKE}

post-install:
.for f in ${HEADERFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/include
.endfor
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf \
		${PREFIX}/etc/spread.conf.sample
.if !exists(${PREFIX}/etc/${PORTNAME}.conf)
	${INSTALL_DATA} ${WRKSRC}/sample.spread.conf \
		${PREFIX}/etc/${PORTNAME}.conf
.endif
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip \
		${PREFIX}/etc/spread.access_ip.sample
.if !exists(${PREFIX}/etc/spread.access_ip)
	${INSTALL_DATA} ${WRKSRC}/sample.spread.access_ip \
		${PREFIX}/etc/spread.access_ip
.endif
	(cd ${WRKSRC}/perl/Spread && ${MAKE} install)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/perl/Spread/test.pl ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DOCSDIR}/LICENSE
.endif
	@${INSTALL} -m 750 -o ${USERS} -g ${GROUPS} -d ${RUNDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
