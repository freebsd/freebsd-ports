# New ports collection makefile for:	tcp_wrapper
# Date created:		27 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	tcp_wrappers
PORTVERSION=	7.6
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	torstenb@FreeBSD.org

.if exists(/usr/include/tcpd.h)
FORBIDDEN=	tcp_wrappers is in the base system
.endif

INSTALLS_SHLIB=	yes

ALL_TARGET=	freebsd
MAN3=		hosts_access.3
MAN5=		hosts_access.5 hosts_options.5
MAN8=		tcpd.8 tcpdchk.8 tcpdmatch.8

post-install:
	@${INSTALL_DATA} ${FILESDIR}/inetd.conf.wrapped.sample ${PREFIX}/etc

update:
	@cd ${FILESDIR} ; co -f $(CVSROOT)/src/etc/inetd.conf,v
	@${SED} -e 's:/usr/libexec/[a-zA-Z]*:${PREFIX}/libexec/tcpd:g'  \
		-e 's:/usr/local/libexec/[a-zA-Z]*:${PREFIX}/libexec/tcpd:g'  \
		-e 's:/usr/local/sbin/[a-zA-Z]*:${PREFIX}/libexec/tcpd:g'  \
		< ${FILESDIR}/inetd.conf  > ${FILESDIR}/inetd.conf.wrapped.sample
	@${RM} -f ${FILESDIR}/inetd.conf
	@${ECHO} "Now manually fixup deamon paths from the /usr/local tree."

.include <bsd.port.mk>
