# ex:ts=8
#
# New ports collection makefile for:	kenny
# Date created:		2001/12/25
# Whom:			Alan E alane@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kenny
PORTVERSION=	1.7
CATEGORIES=	misc perl5
MASTER_SITES=	http://www.h.shuttle.de/mitch/stuff/ \
		http://home.t-online.de/home/dietmar.garbs/download/kenny/
DISTNAME=	kenny.pl-${PORTVERSION}
EXTRACT_SUFX=	.gz
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate text both to and from KennySpeak

USE_PERL5=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

MAN1=		kenny.1
PLIST_FILES=	bin/kenny

program=	kenny
manpage=	kenny.1

.if exists(/usr/bin/pod2man)
POD2MAN=	/usr/bin/pod2man
.elif exists(${LOCALBASE}/bin/pod2man)
POD2MAN=	${LOCALBASE}/bin/pod2man
.else
POD2MAN=	pod2man
.endif

post-extract:
	@${GUNZIP_CMD} -c ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		> ${WRKDIR}/${program}
	@${POD2MAN} ${WRKDIR}/${program} > ${WRKDIR}/${manpage}

post-patch:
	@${PERL} -pi -e "s|/usr/bin/perl|${PERL}|" ${WRKDIR}/${program}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${program} ${PREFIX}/bin/${program}
	@${INSTALL_MAN} ${WRKDIR}/${manpage} ${MANPREFIX}/man/man1/${manpage}

.include <bsd.port.mk>
