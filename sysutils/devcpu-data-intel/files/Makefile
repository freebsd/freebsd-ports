INTEL_UCODE=	Intel-Linux-Processor-Microcode-Data-Files-%%GH_TAGNAME%%/intel-ucode
OUTPUT_DIR=	mcodes

all:	ucode
ucode:	ucode-split
	mkdir -p $(OUTPUT_DIR)
	cd ${OUTPUT_DIR} && \
	for file in \
	  ../${INTEL_UCODE}/[0-9,a-f][0-9,a-f]-[0-9,a-f][0-9,a-f]-[0-9,a-f][0-9,a-f]; do \
		../ucode-split $$file; \
	done

# Use the host cc to compile ucode-split in case of cross-compile
ucode-split: ucode-split.c
	${CC} ucode-split.c -o $@

clean:
	rm -rf $(OUTPUT_DIR) ucode-split
