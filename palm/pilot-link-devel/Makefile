# New ports collection makefile for:    pilot-link
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pilot-link
PORTVERSION=	0.9.3
CATEGORIES=	palm comms tk82
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/ \
		ftp://ftp.forth.org/pub/PalmOS/ryerson/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	dima@freebsd.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_PERL5=	yes
PREFIX=		${LOCALBASE}/pilot
CONFIGURE_ARGS=	--with-perl5=${PERL5}

.include <bsd.port.pre.mk>

CFLAGS!=	${ECHO} "${CFLAGS}" | ${SED} -e 's/-O[0-9a-z]*//g'

MAN1=		dlpsh.1 ietf2datebook.1 install-datebook.1 \
		install-hinote.1 install-memo.1 install-user.1 \
		pilot-xfer.1 read-ical.1
MAN7=		pilot-link.7

post-patch:
	@${CHMOD} 755 ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/pilot-link.sh > ${LOCALBASE}/etc/rc.d/pilot-link.sh
	@${CHMOD} 750 ${LOCALBASE}/etc/rc.d/pilot-link.sh

.include <bsd.port.post.mk>
