# New ports collection makefile for:	maradns
# Date created:				26 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	maradns
PORTVERSION=	0.6.18
CATEGORIES=	net
MASTER_SITES=	http://www.maradns.org/download/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@fix.no

USE_BZIP2=	yes

MAN3=	js_alloc.3 js_append.3 js_atoi.3 js_buf_eof.3 js_buf_getline.3 \
	js_buf_read.3 js_close.3 js_copy.3 js_create.3 js_dealloc.3 \
	js_destroy.3 js_destroy_force.3 js_fgrep.3 js_fgrep_offset.3 \
	js_get_encode.3 js_getline_stdin.3 js_has_sanity.3 js_insert.3 \
	js_issame.3 js_js2str.3 js_length.3 js_lock.3 js_match.3 \
	js_match_offset.3 js_newline_chars.3 js_nonmatch.3 \
	js_nonmatch_offset.3 js_octets.3 js_open.3 js_open_append.3 \
	js_open_read.3 js_open_write.3 js_qstr2js.3 js_read.3 js_set_chsize.3 \
	js_set_encode.3 js_show_stdout.3 js_space_chars.3 js_str2js.3 \
	js_substr.3 js_tolower.3 js_unlock.3 js_val.3 js_write.3
MAN8=	maradns.8

DOCS=	RFC1035.compliance csv1.format draft-skwan-utf8-dns-05.txt \
	example_csv1 example_mararc faq.txt handling.compression \
	mararc.format multiple.qdcount recursive.algorithm \
	resolution.algorithm rfc2044.txt rtest.output www.monty.de \
	../00QuickStart ../CHANGELOG ../ROADMAP

FIXPREFIX=	00QuickStart CHANGELOG doc/man/maradns.8 doc/faq.txt \
		parse/ParseMaraRc.c doc/example_mararc

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
	${INSTALL_DATA} ${WRKSRC}/doc/man/js/* ${PREFIX}/man/man3/
	${INSTALL_DATA} ${WRKSRC}/doc/man/maradns.8 ${PREFIX}/man/man8/
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/doc/maradns
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${PREFIX}/share/doc/maradns
.endfor
.endif

.include <bsd.port.mk>
