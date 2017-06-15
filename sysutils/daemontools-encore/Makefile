# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	daemontools-encore
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://untroubled.org/daemontools-encore/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemontools-encore is a collection of tools for managing UNIX services

LICENSE=	MIT

USES=		gmake

CONFLICTS=	daemontools-[0-9]* freedt-[0-9]* serialmail-[0-9]*

ALL_TARGET=	default

USE_RC_SUBR=	svscan

MANFILES=	\
	envdir.8 \
	envuidgid.8 \
	fghack.8 \
	multilog.8 \
	pgrphack.8 \
	readproctitle.8 \
	setlock.8 \
	setuidgid.8 \
	softlimit.8 \
	supervise.8 \
	svc.8 \
	svok.8 \
	svscan.8 \
	svscanboot.8 \
	svstat.8 \
	svup.8 \
	tai64n.8 \
	tai64nlocal.8

PLIST_FILES=	\
	bin/envdir \
	bin/envuidgid \
	bin/fghack \
	bin/multilog \
	bin/pgrphack \
	bin/readproctitle \
	bin/setlock \
	bin/setuidgid \
	bin/softlimit \
	bin/supervise \
	bin/svc \
	bin/svok \
	bin/svscan \
	bin/svscanboot \
	bin/svstat \
	bin/svup \
	bin/tai64n \
	bin/tai64nlocal \
	%%DOCSDIR%%/README \
	%%DOCSDIR%%/LICENSE  \
	%%DOCSDIR%%/CHANGES  \
	%%DOCSDIR%%/CHANGES.djb \
	${MANFILES:S,^,man/man8/,:S,$,.gz,}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/svscanboot.sh ${STAGEDIR}${PREFIX}/bin/svscanboot
.for binfile in envdir envuidgid fghack multilog pgrphack readproctitle setlock setuidgid softlimit supervise svc svok svscan svstat svup tai64n tai64nlocal
	${INSTALL_PROGRAM} ${WRKSRC}/${binfile} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in README LICENSE CHANGES CHANGES.djb
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor
.for manfile in ${MANFILES}
	${INSTALL_MAN} ${WRKSRC}/${manfile} ${STAGEDIR}${MAN1PREFIX}/man/man8/
.endfor

.include <bsd.port.mk>
