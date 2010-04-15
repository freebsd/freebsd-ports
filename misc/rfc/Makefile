# New ports collection makefile for:	rfc
# Date created:				05 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	rfc
PORTVERSION=	3.2.3
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.dewn.com/rfc/

MAINTAINER=	scf@FreeBSD.org
COMMENT=	Perl script to search for RFC's

RUN_DEPENDS=	w3m:${PORTSDIR}/www/w3m

NO_BUILD=	yes

MAN1=		rfc.1
PLIST_FILES=	bin/rfc \
		"@unexec rm -f %%PREFIX%%/etc/rfc-index"

do-configure:
	@${REINPLACE_CMD} -e 's|/usr/local/etc/rfc|${PREFIX}/etc/rfc| ; \
		s|/usr/local/etc/nmap|${PREFIX}/share/misc/nmap| ; \
		s|400k|1024k| ; \
		s|http://ftp.isi.edu/in-notes|http://www.ietf.org/rfc| ; \
		s|/usr/bin/perl|${PERL}|' ${WRKSRC}/${PORTNAME}-${PORTVERSION}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-${PORTVERSION} \
		${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
