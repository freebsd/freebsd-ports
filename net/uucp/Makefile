# Ports collection makefile for:  uucp
# Date created:			  22 Okt 2001
# Whom:				  Dirk Meyer <dinoex@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uucp
PORTVERSION=	1.06.1
CATEGORIES=	net comms
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=uucp

MAINTAINER=	dinoex@FreeBSD.org

MAN1=	cu.1 uuconv.1 uucp.1 uulog.1 uuname.1 uupick.1 uustat.1 \
	uuto.1 uux.1
MAN8=	uuchk.8 uucico.8 uusched.8 uuxqt.8
EXT1=	uuconv.1 uulog.1 uuname.1 uupick.1 uuto.1
EXT8=	uuchk.8 uusched.8
SAMPLE=	call config dial dialcode passwd port sys1 sys2
GNU_CONFIGURE=		yes
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
INSTALL_TARGET=		install install-info
G_UUCP=			${PREFIX}/libexec/uucp/uuxqt
G_DIALER=		${PREFIX}/bin/cu ${PREFIX}/bin/uuname \
			${PREFIX}/libexec/uucp/uucico

post-configure:
	@${PERL5} -pi -e "s=HAVE_POLL_H 1=HAVE_POLL_H 0=" ${WRKSRC}/config.h
	@${PERL5} -pi -e "s=HAVE_POLL 1=HAVE_POLL 0=" ${WRKSRC}/config.h

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/uuto ${PREFIX}/bin/
	${MV} ${PREFIX}/libexec/uucp/uuchk ${PREFIX}/libexec/uucp/uuconv \
		${PREFIX}/sbin/
	${CHOWN} uucp:uucp ${G_UUCP}
	${CHMOD} 6550 ${G_UUCP}
	${CHOWN} uucp:dialer ${G_DIALER}
	${CHMOD} 6555 ${G_DIALER}
	install-info ${PREFIX}/info/uucp.info ${PREFIX}/info/dir
.for i in ${EXT1}
	${INSTALL_MAN} ${FILESDIR}/${i} ${PREFIX}/man/man1
.endfor
.for i in ${EXT8}
	${INSTALL_MAN} ${FILESDIR}/${i} ${PREFIX}/man/man8
.endfor
.for i in ${SAMPLE}
	${INSTALL_DATA} ${WRKSRC}/sample/${i} ${PREFIX}/etc/uucp/${i}.sample
.endfor

.include <bsd.port.mk>
