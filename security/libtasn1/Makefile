# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	libtasn1
PORTVERSION=	2.14
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtasn1

MAINTAINER=	novel@FreeBSD.org
COMMENT=	ASN.1 structure parser library

USE_LDCONFIG=	yes
USES=		pkgconfig pathfix
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

DOCS=		AUTHORS NEWS README THANKS doc/TODO \
		doc/libtasn1.html doc/libtasn1.pdf doc/libtasn1.ps
INFO=		libtasn1
MAN1=		asn1Parser.1 \
		asn1Coding.1 \
		asn1Decoding.1
MAN3=		asn1_array2tree.3 \
		asn1_bit_der.3 \
		asn1_check_version.3 \
		asn1_copy_node.3 \
		asn1_create_element.3 \
		asn1_delete_element.3 \
		asn1_delete_structure.3 \
		asn1_der_coding.3 \
		asn1_der_decoding.3 \
		asn1_der_decoding_element.3 \
		asn1_der_decoding_startEnd.3 \
		asn1_expand_any_defined_by.3 \
		asn1_expand_octet_string.3 \
		asn1_find_node.3 \
		asn1_find_structure_from_oid.3 \
		asn1_get_bit_der.3 \
		asn1_get_length_ber.3 \
		asn1_get_length_der.3 \
		asn1_get_octet_der.3 \
		asn1_get_tag_der.3 \
		asn1_length_der.3 \
		asn1_number_of_elements.3 \
		asn1_octet_der.3 \
		asn1_parser2array.3 \
		asn1_parser2tree.3 \
		asn1_perror.3 \
		asn1_print_structure.3 \
		asn1_read_node_value.3 \
		asn1_read_tag.3 \
		asn1_read_value.3 \
		asn1_strerror.3 \
		asn1_write_value.3 \
		libtasn1_perror.3 \
		libtasn1_strerror.3

.if !defined(NOPORTDOCS)
NO_STAGE=	yes
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
