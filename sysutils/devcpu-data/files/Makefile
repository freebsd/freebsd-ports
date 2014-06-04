AMD_UCODE_DIR=	amd-ucode-2012-09-10
AMD_UCODE=	$(AMD_UCODE_DIR)/microcode_amd.bin \
		$(AMD_UCODE_DIR)/microcode_amd_fam15h.bin
INTEL_UCODE=	microcode.dat
OUTPUT_DIR=	mcodes
all:	ucode
ucode:	ucode-tool
	mkdir -p $(OUTPUT_DIR)
	./ucode-tool -o $(OUTPUT_DIR) -i $(INTEL_UCODE)
	./ucode-tool -o $(OUTPUT_DIR) -a $(AMD_UCODE)

# Use the host cc to compile ucode-tool in case of cross-compile
ucode-tool: ucode-tool.c
	cc ucode-tool.c -o $@

clean:
	rm -rf $(OUTPUT_DIR) ucode-tool
