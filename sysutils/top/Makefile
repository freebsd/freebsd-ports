# New ports collection makefile for:   top
# Date created:        9 January 2004
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	top
PORTVERSION=	${VERSION}.${BETA}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:main/:S/%SUBDIR%/unixtop/} \
		http://www.mavetju.org/download/adopted/:freebsd
MASTER_SITE_SUBDIR=	unixtop:main
DISTFILES=	${PORTNAME}-${VERSION}beta${BETA}${EXTRACT_SUFX}:main \
		top-${VERSION}beta${BETA}-src-FreeBSD${OSREL:S/.//}${EXTRACT_SUFX}:freebsd

PATCH_SITES=	http://www.mavetju.org/download/adopted/
PATCHFILES=	top-${VERSION}beta${BETA}-contrib-FreeBSD${OSREL:S/.//}.gz

MAINTAINER=	edwin@mavetju.org
COMMENT=	Display and update information about the top cpu processes

WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}beta${BETA}
VERSION=	3.5
BETA=		13
MAN1=		top.1

USE_REINPLACE=	yes

.if defined(TOP_OVERWRITE_BASE)
PREFIX=		/usr
PKGNAMESUFFIX=	-overwrite-base
MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=--mandir=${MANPREFIX}/man
PLIST_SUB+=	NOTBASE="@comment "
PLIST_SUB+=	BASE=""
PKGMESSAGE=	${FILESDIR}/pkg-message-base
.else
PLIST_SUB+=	BASE="@comment "
PLIST_SUB+=	NOTBASE=""
.endif

CFLAGS+=	-DORDER -DHAVE_STRERROR -DHAVE_GETOPT -DBETA=\\"beta${BETA}\\"

FREEBSDFILES=	machine.c sigdesc.h top.local.1

.include <bsd.port.pre.mk>

OSREV!=		${UNAME} -r | ${TR} -cd A-Za-z0-9

.if ${OSVERSION} >= 490102 && ${OSVERSION} < 500000
BROKEN=		"Does not fetch on 4.10"
.endif

.if ${OSVERSION} < 470000
IGNORE=		"This port is not supported for this OS version."
.endif

.if !defined(TOP_OVERWRITE_BASE)
pre-everything::
	@${ECHO_MSG} "Use TOP_OVERWRITE_BASE=yes to install over the default top"
	@/bin/sleep 5
.endif

#
# Use the same method for configuring as the base top installation
#
post-extract:
.for f in ${FREEBSDFILES}
	@${CP} ${WRKDIR}/src/usr.bin/top/${f} ${WRKSRC}/$f
.endfor
	@${CP} ${WRKSRC}/Makefile.X ${WRKSRC}/Makefile
	@${CP} ${WRKSRC}/top.local.H ${WRKSRC}/top.local.h
	@${CP} ${WRKSRC}/top.X ${WRKSRC}/top.1
	@${CAT} ${WRKDIR}/src/usr.bin/top/top.local.1 >> ${WRKSRC}/top.1

post-patch:
	${REINPLACE_CMD} \
		-e 's,%shell%,${SH},g' \
		-e 's,%cc%,${CC},g' \
		-e 's,%awk%,${AWK},g' \
		-e 's,%install%,${INSTALL},g' \
		-e 's,%owner%,${BINOWN},g' \
		-e 's,%group%,kmem,g' \
		-e 's,%mode%,2555,g' \
		-e 's,%bindir%,${PREFIX}/bin,g' \
		-e 's,%mandir%,${MANPREFIX}/man/man1/,g' \
		-e 's,%manext%,1,g' \
		-e 's,%mansty%,man,g' \
		-e 's,%signal%,,g' \
		-e 's,%topn%,-1,g' \
		-e 's,%delay%,2,g' \
		-e 's,%cflgs%,${CFLAGS},g' \
		-e 's,%cdefs%,,g' \
		-e 's,%libs%,-lkvm,g' \
		-e 's,%termcap%,-ltermcap,g' \
		-e 's,%math%,-lm,g' \
		-e 's,%osrev%,-DOSREV=${OSREV},g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e 's,%LoadMax%,5.0,g' \
		-e 's,%TableSize%,20011,g' \
		-e 's,%NominalTopn%,18,g' \
		-e 's,%topn%,-1,g' \
		-e 's,%delay%,2,g' \
		-e 's,%random%,1,g' \
		${WRKSRC}/top.local.h \
		${WRKSRC}/top.1 \

.if defined(TOP_OVERWRITE_BASE)
post-install:
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
