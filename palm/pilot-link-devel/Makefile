# New ports collection makefile for:    pilot-link
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilot-link
PORTVERSION=	0.9.5
PORTREVISION=	3
CATEGORIES=	palm comms tk83
MASTER_SITES=	http://www.pilot-link.org/source/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	dima@FreeBSD.org

LIB_DEPENDS=	tk83:${PORTSDIR}/x11-toolkits/tk83 \
		giconv:${PORTSDIR}/converters/libiconv

USE_BZIP2=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_PERL5=	yes

MAN1=		dlpsh.1 ietf2datebook.1 install-datebook.1 \
		install-hinote.1 install-memo.1 install-user.1 \
		pilot-addresses.1 pilot-xfer.1 read-ical.1
MAN7=		pilot-link.7

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-perl5=${PERL5} --with-libiconv=${LOCALBASE}

post-patch:
	# FreeBSD installs -lgiconv instead of -liconv. Patch configure.
	${PERL} -pi -e 's/([^g])iconv.h/\1giconv.h/g;' \
		-e 's/-liconv/-lgiconv/g' ${WRKSRC}/${CONFIGURE_SCRIPT} \
		${WRKSRC}/libsock/util.c
	# Remove the FORCE tag, which forced recompiling/relinking
	# of the otherwise up-to-date files.
	${PERL} -pi -e 's/: FORCE/:/;' -e 's/getopt.h//;' ${WRKSRC}/Makefile.in
	# When the day comes, and pilot-link starts using longopt,
	# we'll start using -lgnugetopt. No need for this files:
	${RM} -f ${WRKSRC}/getopt*

.include <bsd.port.mk>
