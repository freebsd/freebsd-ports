# New ports collection makefile for:	elmo
# Date created:				2003-09-27
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	elmo
PORTVERSION=	0.8.3
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:sf/} \
		${MASTER_SITE_SAVANNAH:S/$/:sav/}
MASTER_SITE_SUBDIR=	${PORTNAME}/:sf \
			${PORTNAME}/unstable.pkg/${PORTVERSION}/:sav
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sf,sav

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Receive, filter, read, compose and send mail at the text console

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.5:${PORTSDIR}/devel/gettext-old

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
INFO=		elmo
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
MAN1=		elmo.1 elmoconf.pl.1
PLIST=		${WRKDIR}/pkg-plist
USE_PERL5=	yes

pre-extract:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} sleeping ten seconds--press control-C to cancel build
	@${ECHO_CMD} 
	@sleep 10

pre-install:
	${RM} -f ${PLIST}
.for ii in elmo elmoconf.pl
	${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
.for ii in de pl
	${ECHO_CMD} share/locale/${ii}/LC_MESSAGES/elmo.mo >> ${PLIST}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/elmo ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/src/elmoconf.pl ${PREFIX}/bin/
.for ii in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${ii} ${MANPREFIX}/man/man1
.endfor
.for ii in de pl
	${INSTALL_DATA} ${WRKSRC}/po/${ii}.gmo \
		${PREFIX}/share/locale/${ii}/LC_MESSAGES/elmo.mo
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/elmo.info ${PREFIX}/info/
	- install-info --info-dir=${PREFIX}/info ${PREFIX}/info/elmo.info

.include <bsd.port.mk>
