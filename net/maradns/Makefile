# New ports collection makefile for:	maradns
# Date created:				26 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	maradns
PORTVERSION=	0.8.06
CATEGORIES=	net
MASTER_SITES=	http://www.maradns.org/download/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@fix.no

USE_BZIP2=	yes

MAN1=	askmara.1 getzone.1
MAN8=	maradns.8 zoneserver.8

DOCS=	RFC1035.compliance csv1.format draft-skwan-utf8-dns-05.txt \
	example_csv1 example_mararc faq.txt handling.compression \
	mararc.format multiple.qdcount recursive-case-insensitive \
	recursive.algorithm resolution.algorithm rfc2044.txt rtest.output \
	www.monty.de ../0QuickStart ../CHANGELOG.html ../ROADMAP ../CREDITS

FIXPREFIX=	00QuickStart CHANGELOG.html doc/man/maradns.8 doc/faq.txt \
		doc/man/zoneserver.8 parse/ParseMaraRc.c doc/example_mararc

post-patch:
.for f in ${FIXPREFIX}
	${PERL} -pi -e "s@/etc/maradns@${PREFIX}/etc/maradns@g; \
		s@/etc/mararc@${PREFIX}/etc/mararc@g" ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server/maradns ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/tuzona/zoneserver ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/tuzona/getzone ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/tools/askmara ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/doc/example_mararc ${PREFIX}/etc/mararc.sample
	${INSTALL_MAN} ${WRKSRC}/doc/man/maradns.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/doc/man/zoneserver.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/doc/man/askmara.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/getzone.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/doc/maradns
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${PREFIX}/share/doc/maradns
.endfor
.endif

.include <bsd.port.mk>
